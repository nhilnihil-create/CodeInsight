#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(int I = (A); I < int(B); ++I)

int main(){
    int N;
    cin >> N;
    vector<int> x(N),y(N);
    FOR(i,0,N)cin >> x[i] >> y[i];
    double ans = 0;
    int n = 2000;
    for(double sita=0;sita<=2*M_PI;sita+=2.0*M_PI/n){
        double tox = cos(sita);
        double toy = sin(sita);
        int nowx=0;
        int nowy=0;
        FOR(i,0,N){
            double dot = tox*x[i] + toy*y[i];
            if(dot >= 0.0){
                nowx += x[i];
                nowy += y[i];
            }
        }
        double anst = sqrt((double)nowx*nowx + (double)nowy*nowy);
        ans = max(ans,anst);
    }
    cout<<fixed<<setprecision(15)<<ans<<endl;
}