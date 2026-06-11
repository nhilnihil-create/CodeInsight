#include<iostream>
#include<algorithm>
using namespace std;
struct bisai{
	int begin;
	int end;
};
bisai a[1000005];
struct rule1{
	bool operator()(const bisai &s1,const bisai &s2){
		return s1.end<s2.end;
	}
};
int main(){
	int n,i,t=-2147483647,count=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i].begin>>a[i].end;
		a[i].begin-=a[i].end;
		a[i].end=a[i].begin+(a[i].end<<1);
	}
	sort(a,a+n,rule1());
	for(i=0;i<n;i++){
		//printf("a[%d].bigin=%d,end=%d\n",i,a[i].begin,a[i].end);
		if(a[i].begin>=t){
			//cout<<a[i].end<<endl;
			//cout<<"t="<<t<<endl;
			count++;
			t=a[i].end;
		}
	}
	cout<<count;
} 