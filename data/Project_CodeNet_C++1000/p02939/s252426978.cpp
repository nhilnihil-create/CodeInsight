#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string S;
    cin >> S;
    vector<int> count(2*100000,0);
    string pre = "";
    string target = "";
    int _count =0;
    for(int i=0; i<S.size(); i++){
        target += S[i];
        if(i<4){
            if(target != pre){
                _count += 1;
                count[i] = _count;
                pre = target;
                target = "";
            }else{
                count[i] = _count;
            }
        }else{
            if(S[i] != S[i-1]){
                count[i] = count[i-1] + 1;
            }else{
                count[i] = count[i-3] + 2;
            }
        }

    }
    cout << count[S.size()-1] << endl;
    return 0;
}
