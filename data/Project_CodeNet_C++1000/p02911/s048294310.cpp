#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> member(n, k - q);
    int tmp;
    for(int i = 0; i < q; i++){
        cin >> tmp;
        member.at(tmp - 1)++;
    }

    for(int i = 0; i < member.size(); i++){
        if(member.at(i) > 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}