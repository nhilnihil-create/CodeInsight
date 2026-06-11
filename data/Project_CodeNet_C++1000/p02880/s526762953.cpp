#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= 9;i++){
        for(int j = 1;j <= 9;j++){
            if (n == i*j){
                cout << "Yes";
                exit(0);
            }
        }
    }
    cout << "No";
}