#include <bits/stdc++.h>

using namespace std;
 
int main() {
    list<char> ans;
    string S;
    long long Q;
    bool aux = false;
    cin >> S >> Q;
    for(long long i = 0; i < S.length(); i++){ 
        ans.push_back(S[i]); 
    }
    for(long long i = 0; i < Q; i++){
        long long T;
        cin >> T;
        if (T == 1){
            aux = !aux;
        } else{
            long long F;
            char C;
            cin >> F >> C;
            if (F == 1){
                if (!aux) 
                    ans.push_front(C);
                else 
                    ans.push_back(C);
            } else{
                if (!aux)
                    ans.push_back(C);
                else 
                    ans.push_front(C);
            }
        }
    }
    if (aux){
        ans.reverse();
    }
    for (auto i = ans.begin(); i != ans.end(); i++){
        cout << *i;
    }
    cout << endl;
    return 0;
}