#include<iostream>
using namespace std;

int main(){
    string w;
    cin >> w;
    int ans = 0;
    if(w[0] == 'R'){
        ans++;
    }
    for(int i = 1;i < w.size();i++){
        if(w[i - 1] == 'R' && w[i] ==  'R') ans++;
        else if(w[i] == 'R') ans = max(ans, 1);
    }

    cout << ans << endl;
    return 0;
}