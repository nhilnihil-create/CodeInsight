#include <iostream>

using namespace std;

int main()
{
    int n;
    long long d;
    int cnt=0;
    cin>>n>>d;
    d=d*d;
    while(0<n--) {
        int x,y; cin>>x>>y;
        long long dx;
        dx=1ll*x*x+1ll*y*y;
        if(dx<=d) cnt++;
    }
    cout << cnt << '\n';
}
