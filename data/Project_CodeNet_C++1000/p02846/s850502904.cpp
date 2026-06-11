#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll T1,T2,A1,A2,B1,B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    A1 *= T1;
    B1 *= T1;
    A2 *= T2;
    B2 *= T2;
    if(A1 + A2 == B1 + B2){
        cout << "infinity" << endl;
        return 0;
    }else if(A1 + A2 > B1 + B2){
        if(A1 > B1){
            cout << 0 << endl;
            return 0;
        }else{
            //cout << "a"<<endl;
            ll C = B1 - A1;
            ll D = A1 + A2 - B1 - B2;
            //cout << C << " " << D << endl;
            if(C%D==0){
                cout << (ll((C-1)/D)+1)*2 << endl;
            }else{
                cout << (ll((C-1)/D)+1)*2-1 << endl;
            }
            return 0;
        }
    }else{
        if(B1 > A1){
            cout << 0 << endl;
            return 0;
        }else{
            ll C = A1 - B1;
            ll D = B1 + B2 - A1 - A2;
            if(C%D==0){
                cout << (ll((C-1)/D)+1)*2 << endl;
            }else{
                cout << (ll((C-1)/D)+1)*2-1 << endl;
            }
            return 0;
        }
    }
    
    //ll prev = 0;
    //ll prevB = 0;
    //ll ans = 0;
    /*
    while(true){
        ll nowA = prev + T1*A1;
        ll nowB = T1*B1;
        ll t = nowA - nowB;
        nowA = t + T2*A2;
        nowB = T2*B2;
        ll u = nowA - nowB;
        if(t > 0 && u > 0 || t < 0 && u < 0){
            break;
        }else if(t*u == 0){
            cout << "infinity" << endl;
            return 0;
        }
        ans++;
        prev = u;
        cout << prev << endl;
        //prevB = nowB;
    }
    /*
    ll prevA=0;
    ll prevB=0;
    ll t = 0;
    ll u = -(A1-B1);
    bool flag = false;
    while(true){
        ll nowA = prevA + T1*A1;
        ll nowB = prevB + T1*B1;
        t = nowA - nowB;
        if(t>0 && u>0 || t<0 && u<0){
            if(flag){
                break;
            }else{
                flag = true;
                continue;
            }
        }else if(t*u == 0){
            cout << "infinity" << endl;
            return 0;
        }else{
            flag = false;
        }
        cout << nowA << " " << nowB << endl;
        nowA += T2*A2;
        nowB += T2*B2;
        cout << nowA << " " << nowB << endl;
        u = nowA - nowB;
        cout << "t " << t << " " << u <<endl;
        if(t>0 && u>0 || t<0 && u<0){
            if(flag){
                break;
            }else{
                flag = true;
                continue;
            }
        }else if(t*u == 0){
            cout << "infinity" << endl;
            return 0;
        }else{
            flag = false;
        }
        ans++;
        prevA = nowA;
        prevB = nowB;
        //cout << prev << endl;
        //prevB = nowB;
    }*/
    //cout << ans << endl;

}