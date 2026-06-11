#include <iostream>
#include <cmath>
#include<algorithm>
#include<vector>


using namespace std;

int main()
{
    bool rev = false;

    string S;
    vector<char> b, e;
    cin >> S;

    int Q;
    cin >> Q;


    for (int q = 0; q < Q; q++){
        int T;
        cin >> T;
        if(T == 1){
            rev = (!rev);
        }else{
            int F;
            char C;
            cin >> F >> C;
            if(F == 1){
                if(rev){
                    e.push_back(C);
                }else{
                    b.push_back(C);
                }
            }else{
                if(rev){
                    b.push_back(C);
                }else{
                    e.push_back(C);
                }
            }
        }

    }
    
    if(rev){
        reverse(e.begin(), e.end());
        reverse(S.begin(), S.end());
        for (auto itr = e.begin(); itr != e.end(); itr++){
            cout << *itr;
        }
        cout << S;
        for (auto itr = b.begin(); itr != b.end(); itr++){
            cout << *itr;
        }
        cout << '\n';
    }else{
        reverse(b.begin(), b.end());
        for (auto itr = b.begin(); itr != b.end(); itr++)
        {
            cout << *itr;
        }
        cout << S;
        for (auto itr = e.begin(); itr != e.end(); itr++)
        {
            cout << *itr;
        }
        cout << '\n';
    }
}