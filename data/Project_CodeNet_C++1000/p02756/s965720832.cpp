#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    int T,F;
    char C;

    bool reverse=false;

    for(int i=0; i<Q; i++){
        cin >> T;
        if(T==1){
            reverse = (!reverse);
        }else{
            cin >> F >> C;
            if(F==1){
                string str(1,C);
                int position = reverse*S.size();
                S.insert(position, str);
            }else{
                string str(1,C);
                int position = (!reverse)*S.size();
                S.insert(position, str);                
            }
        }
    }

    if(reverse){
        for(int i=S.size()-1; i>=0; i--){
            cout << S[i];
        }
    }else{
        for(int i=0; i<=S.size()-1; i++){
            cout << S[i];
        }        
    }
    cout << endl;

    return 0;
}