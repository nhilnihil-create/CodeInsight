#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int mark,input;
    cin >> mark;
    rep(i,n-1){
        cin >> input;
        if(input<mark){
            if(mark - input >= 2){
                cout << "No"<<endl;
                return 0;
            }
        }else if(input>=mark){
            mark = input;
        }
    }
    cout << "Yes"<<endl;
}