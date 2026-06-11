#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    map<int,int> A;
    bool t = true;
    rep(i,N) {
        int a;
        cin >> a;
        A[a]++;
        if (a!=0) t = false;
    }
    if (t) {
        cout << "Yes" << endl;
    }
    else {
        if (A.size()==3) {
            t = true;
            int tmp = 0;
            for (auto a:A) {
                tmp ^= a.first;
                if (a.second*3!=N) t = false;
            }            
            if (tmp!=0) t = false;
            if (t) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else if (A.size()==2) {
            int tmp = 0;
            t = true;
            for (auto a:A) {
                if (a.second*3==N) {
                    tmp^=a.first;
                }
                else if (a.second*3==N*2){
                    tmp^=a.first;
                    tmp^=a.first;
                }
                else {
                    t = false;
                }
            }
            if (tmp!=0) t = false;
            if (t) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            cout << "No" << endl;
        }
    }

}

