// file creato da gio il 2020-09-14 17:13:19.374937

#include <bits/stdc++.h>

#ifdef FAST
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#endif

#define MOD 1000000007
#define S second
#define F first
#define PB push_back
#define ll long long 

using namespace std;


#define MN 200000
int unf[MN];
int sub[MN];

int find(int a){
    if(a==unf[a]) return a;
    else return unf[a]=find(unf[a]);
}

void conc(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return;
    if(sub[a]<sub[b])swap(a,b);
    sub[a]+=sub[b];
    unf[b]=a;
}

int main(){
	//freopen("output","w",stdout);
	//freopen("input","r",stdin);
#ifdef FAST
	ios::sync_with_stdio(0);
  	cin.tie(0);
#endif

	int n,q;
	cin >> n>>q;
    for(int i=0;i<n;i++){unf[i]=i;sub[i]=1;}
    for(int i=0;i<q;i++){
        int a,b,c;
        cin >>a>>b>>c;
        if(a)
            cout <<(find(b)==find(c)?1:0)<<endl;
        else
            conc(b,c);

    }

}
