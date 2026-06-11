#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    string a;
    cin >> a;
    rep0(i,3){
        if(a[i]==a[i+1]){
            cout << "Bad" << endl;
            exit(0);
        }
    }
    cout << "Good" << endl;
}
