#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    string s;
    cin >> s;
    vector<int> data(s.size(),1);
    ll right=0;
    ll left = 0;
    ll rposi;
    ll lposi;

    rep(i,0,s.size()+1){
        if(left>0&&s[i]=='R'||i==s.size()){
            ll M = max(left,right);
            int L,R;
            lposi = right;
            rposi = right-1;

            if(left<right){
                L = (left+right)/2;
                R = left+right-L;
            }else{
                R = (left+right)/2;
                L = left+right-R;
            }
            M--;
            //cout<<M<<R<<L<<endl;
            if(M%2==0){//終わっ時の状態が最終状態
                rep(j,0,right+left){
                    if(j==rposi){
                        cout<<R<<" ";
                    }else if(j==lposi){
                        cout<<L<<" ";
                    }else{
                        cout<<0<<" ";
                    }
                }
            }else{
                rep(j,0,right+left){
                    if(j==rposi){
                        cout<<L<<" ";
                    }else if(j==lposi){
                        cout<<R<<" ";
                    }else{
                        cout<<0<<" ";
                    }
                }
            }
            left=0;
            right=1;
            //rposi = i;

        }else if(s[i]=='L'){
            // if(left==0){
            //     lposi=i;
            // }
            left++;
        }else if(s[i]=='R'){
            //rposi=i;
            right++;
        }
    }
    cout<<endl;
  return 0;
}