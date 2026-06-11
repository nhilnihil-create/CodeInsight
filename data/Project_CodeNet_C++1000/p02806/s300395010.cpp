#include<map>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}
string s[10005],c;
int n,ans,a[100005];
int main(){
    in(n);
    for(int i=1;i<=n;i++)cin>>s[i]>>a[i];
    cin>>c;
    for(int i=n;i>=1;i--){
        if(s[i]==c)break;
        ans+=a[i];
    }
    cout<<ans<<endl;
	return 0;
}
