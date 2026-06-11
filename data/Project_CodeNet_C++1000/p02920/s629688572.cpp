#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define N 1000010
multiset<int> s;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a[N],tot;
int b[N],bn;
int main(){
	n=read();
	tot=1<<n;
	for(int i=1;i<=tot;i++){
		a[i]=read();
		s.insert(a[i]);
	}
	b[++bn]=(*--s.end());
	s.erase(s.find(b[bn]));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(1<<(i-1));j++){
			if(*s.begin()>=b[j]){
				cout<<"No"<<endl;
				return 0;
			}
			b[++bn]=(*--s.lower_bound(b[j]));
			s.erase(s.find(b[bn]));
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
