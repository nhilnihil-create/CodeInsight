#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define F first
#define S second
typedef pair<double, double> P;
vector<P> ans;
double Pythagorean(double x, double y){
    return sqrt(x * x + y * y);
}
void KochCurve(P s, P e, int n){
    if(n){
        double l = Pythagorean((e.F - s.F) / 3, (e.S - s.S) / 3);
        l *= sqrt(3) / 2;
        P direct = MP(e.F - s.F, e.S - s.S);
        double temp = Pythagorean(direct.F, direct.S);
        direct.F /= temp; direct.S /= temp;
        
        P c1 = MP((e.F - s.F) / 3 + s.F, (e.S - s.S) / 3 + s.S);
        P c2 = MP((e.F - s.F) / 2 - direct.S * l + s.F, (e.S - s.S) / 2 + s.S + direct.F * l);
        P c3 = MP((e.F - s.F) / 3 * 2 + s.F, (e.S - s.S) / 3 * 2 + s.S);
        n--;
        KochCurve(s, c1, n);
        KochCurve(c1, c2, n);
        KochCurve(c2, c3, n);
        KochCurve(c3, e, n);
        n++;
    }
    else{
        ans.push_back(e);
        return;
    }
}
int main(){
    int n;
    P s = MP(0, 0), e = MP(100, 0);
    cin >> n;
    KochCurve(s, e, n);
    cout << s.F << " " << s.S << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].F << " " << ans[i].S << endl;
    }
}
