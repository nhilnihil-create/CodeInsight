#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<int> R;
vector<int> B;
vector<int> T;

int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    for(int i = 0; i < a; i++){
        int p;
        cin >> p;
        R.push_back(p);
    }
    for(int i = 0; i < b; i++){
        int q;
        cin >> q;
        B.push_back(q);
    }
    for(int i = 0; i < c; i++){
        int r;
        cin >> r;
        T.push_back(r);
    }
    sort(R.begin(), R.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    for(int i = 0; i < x; i++)T.push_back(R[i]);
    for(int i = 0; i < y; i++)T.push_back(B[i]);
    sort(T.begin(), T.end(), greater<int>());
    long long int ans = 0;
    for(int i = 0; i < x+y; i++)ans += T[i];
    cout << ans << endl;
    return 0;
}