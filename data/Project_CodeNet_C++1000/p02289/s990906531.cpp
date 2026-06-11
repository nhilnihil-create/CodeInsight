#include<functional>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;


int highest_pop(unsigned int b){
	int res=0;
	for(int i=4;i>=0;i--){
		int shift=1<<i;
		if(b>>shift){
			b>>=shift;
			res|=shift;
		}
	}
	return res;
}
int highest_popll(unsigned long long b){
	int res=0;
	for(int i=5;i>=0;i--){
		int shift=1<<i;
		if(b>>shift){
			b>>=shift;
			res|=shift;
		}
	}
	return res;
}



template<int U=31> 
class MultiSet{
	unsigned int summary;
	MultiSet<U-5> *ch[1<<5];
	static int low_bits(unsigned int a){
		return a&((1<<U-5)-1);
	}
	static int high_bits(unsigned int a){
		return a>>(U-5);
	}
	static int index(unsigned int high,unsigned int low){
		return high<<U-5|low;
	}
public:
	MultiSet():summary(0){
		for(int i=0;i<(1<<5);i++)ch[i]=NULL;
	}
	~MultiSet(){clear();}
	void clear(){
		summary=0;
		for(int i=0;i<(1<<5);i++){
			delete ch[i];
			ch[i]=NULL;
		}
	}
	void insert(int v){
		unsigned int high=high_bits(v);
		summary|=1<<high;
		if(!ch[high])ch[high]=new MultiSet<U-5>();
		ch[high]->insert(low_bits(v));
	}
	bool erase(int v){
		unsigned int high=high_bits(v);
		if(!ch[high])return true;
		if(!ch[high]->erase(low_bits(v))){
			delete ch[high];
			ch[high]=NULL;			
			return summary&=~(1<<high);
		}
		return true;
	}
	int nextvalue(int v)const{
		unsigned int high=high_bits(v);
		unsigned int low=low_bits(v);
		int a;
		if(ch[high] && (a=ch[high]->nextvalue(low))!=-1){
			return index(high,a);
		}else{
			high=summary&~((1<<high)-1)&~(1<<high);
			if(!high)return -1;
			high=highest_pop(high&-high);
			return index(high,ch[high]->min());
		}
	}
	int prevvalue(int v)const{
		unsigned int high=high_bits(v);
		unsigned int low=low_bits(v);
		int a;
		if(ch[high] && (a=ch[high]->prevvalue(low))!=-1){
			return index(high,a);
		}else{
			high=summary&((1<<high)-1);
			if(!high)return -1;
			high=highest_pop(high);
			return index(high,ch[high]->max());
		}
	}
	int min()const{
		if(!summary)return -1;
		unsigned int high=highest_pop(summary&-summary);
		return index(high,ch[high]->min());
	}
	int max()const{
		if(!summary)return -1;
		unsigned int high=highest_pop(summary);
		return index(high,ch[high]->max());
	}
	int count(int v)const{
		unsigned int high=high_bits(v);
		if(!ch[high])return 0;
		return ch[high]->count(low_bits(v));
	}
};


template<> 
class MultiSet<6>{
	unsigned long long summary;
	int cnt[1<<6];
public:
	MultiSet(){clear();}
	void clear(){
		summary=0;
		memset(cnt,0,sizeof(cnt));
	}
	void insert(int v){
		summary|=1ull<<v;
		cnt[v]++;
	}
	bool erase(int v){
		if(cnt[v])cnt[v]--;
		if(cnt[v]==0)summary&=~(1ull<<v);
		return summary;
	}
	int nextvalue(int v)const{
		long long a=summary&~((1ull<<v)-1)&~(1ull<<v);
		if(!a)return -1;
		return highest_popll(a&-a);
	}
	int prevvalue(int v)const{
		long long a=summary&((1ull<<v)-1);
		if(!a)return -1;
		return highest_popll(a);
	}
	int min()const{
		if(!summary)return -1;
		return highest_popll(summary&-summary);
	}
	int max()const{
		if(!summary)return -1;
		return highest_popll(summary);
	}
	int count(int v)const{
		return cnt[v];
	}
};




int main(){
	MultiSet<> heap;
	string s;
	while(1){
		cin>>s;
		if(s=="end")break;
		if(s=="insert"){
			int n;
			cin>>n;
			heap.insert(n);
		}else if(s=="extract"){
			int a=heap.max();
			cout<<a<<endl;
			heap.erase(a);
		}
	}
	return 0;
}