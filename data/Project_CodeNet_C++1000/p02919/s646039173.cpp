#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
#define N 100010
set<int> s;
set<int>::iterator it,tmp;
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
int n,a[N],pos[N],mx,mn;
ll ans;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		pos[a[i]]=i;
	}
	s.insert(pos[n]);
	mx=mn=pos[n];
	//cout<<" "<<pos[n]<<endl;
	for(int i=n-1;i>=1;i--){
		it=s.lower_bound(pos[i]);
		int l=0,r=n+1,x=0,y=n+1;
		//cout<<pos[i]<<" "<<(*it)<<endl;
		if(pos[i]<mx){
			//cout<<"tt"<<endl;
			r=(*it);
			if(r!=mx){
				tmp=s.lower_bound(r);
				tmp++;
				y=(*tmp);
			}
		}
		if(pos[i]>mn){
			l=(*--it);
			if(l!=mn){
				tmp=(s.lower_bound(l));
				x=(*--tmp);
			}
		}
		//cout<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
		ans+=(ll)i*(y-r)*(pos[i]-l)+(ll)i*(l-x)*(r-pos[i]);
		s.insert(pos[i]);
		mx=max(pos[i],mx);
		mn=min(pos[i],mn);
		//cout<<" "<<pos[i]<<endl;
		//cout<<endl<<endl;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
