#include<iostream>

using namespace std;

typedef long long LL;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    LL ans1=(LL)a*c;
    LL ans2=(LL)a*d;
    LL ans3=(LL)b*c;
    LL ans4=(LL)b*d;
    //cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
    LL ans=max(ans1,ans2);
    ans=max(ans,max(ans3,ans4));
    cout<<ans<<endl;
    return 0;
}