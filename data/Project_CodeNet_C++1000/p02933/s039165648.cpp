#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;


void solve(long long a, std::string s){
    if(a >= 3200){
        cout<<s<<endl;
    }
    else{
        cout<<"red"<<endl;
    }
}

int main(){
    long long a;
    scanf("%lld",&a);
    std::string s;
    std::cin >> s;
    solve(a, s);
    return 0;
}
