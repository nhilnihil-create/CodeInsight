#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int cm[N];

int main(){
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(i == 0){
            cm[i] = (s[i] == 'R');
            continue;
        }
        cm[i] = cm[i - 1] + (s[i] == 'R');
    }
    int bst = cm[n - 1];
    for(int i = 0; i < n; i++){
        int reds = (cm[n - 1] - cm[i]);
        int alre = cm[i];
        if(alre == i+1){
            bst = min(bst , reds);
        } if(cm[n-1] - cm[i] - ((i+1) - cm[i]) >= 0) {
            bst = min(bst , ((i+1) - cm[i]) + (cm[n - 1] - cm[i] - ((i+1) - cm[i]) ));
            //cout << i << " : " << bst << "\n";
        }
    }
    cout << bst << "\n";
}
