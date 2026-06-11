#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;

int main()
{
    int N,K,Q;
    cin >> N >> K >> Q;
    vector<int> res(N+1);
    rep0(i,Q){
        int input;
        cin >> input;
        res[input]++;
    }
    rep1(i,N){
        if(K-Q+res[i]>0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

}
