#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<utility>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> Pi;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}

int main(){
    int n;
    cin >> n;
    vector<Pi> p(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(b, a);
    }

    sort(p.begin(), p.end()); //締め切りでソート
    ll deadline = p.back().first;
    ll time = 0;
    for(int i = 0; i < n; i++){
        if(time+p[i].second > p[i].first){
            cout << "No" << endl;
            return 0;
        }
        time += p[i].second;
    }

    cout << "Yes" << endl; 
    return 0;
}
