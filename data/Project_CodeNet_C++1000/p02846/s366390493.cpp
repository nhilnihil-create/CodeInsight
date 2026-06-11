#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
int main(){
    ll t1, t2, a1, a2, b1, b2;
    while(cin>>t1>>t2>>a1>>a2>>b1>>b2){
        ll ans=0;
        ll tmp1=t1*a1;
        ll tmp2=t2*a2;
        ll tmp3=t1*b1;
        ll tmp4=t2*b2;
        // cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<endl;
        // cout<<tmp1-tmp3<<" "<<tmp2-tmp4<<endl;
        if((tmp1>tmp3&&tmp2>tmp4)||(tmp1<tmp3&&tmp2<tmp4)){
            ans=0;
        }
        else if(tmp1+tmp2==tmp3+tmp4){
            ans=-1;
        }
        else{
            if(tmp1>tmp3){
                if(tmp4-tmp2<tmp1-tmp3){
                    ans=0;
                }
                else{
                    ll tmp= tmp4-tmp2-(tmp1-tmp3);
                    ans=(tmp1-tmp3)/tmp+(tmp1-tmp3+tmp-1)/tmp;
                }
            }
            else{ // tmp1 <= tmp3
                if(tmp2-tmp4 < tmp3-tmp1){
                    ans=0;
                }
                else{
                    ll tmp=tmp2-tmp4-(tmp3-tmp1);
                    ans=(tmp3-tmp1)/tmp+(tmp3-tmp1+tmp-1)/tmp;
                }
            }
        }
        if(ans==-1){
            cout<<"infinity"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
  return 0;
}


