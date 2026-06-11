#include<iostream>
using namespace std;

int main(){
    bool plus = false, ilast = false, newlast = false;
    string S;
    long long K;
    int cnt1 = 0, cnt2 = 0;

    cin >> S >> K;

    for(int i=0; i<S.length(); i++){
        if(i == S.length() - 1) ilast = true;
        else if(S[i] == S[i+1]){
            cnt1++;
            i++;
        }
    }
    if(ilast && S[S.length() - 1] == S[0]){
        string newString = S[0] + S;
        plus = true;

        for(int i=0; i<S.length() + 1; i++){
            if(i == S.length()) newlast = true;
            else if (newString[i] == newString[i+1]){
            cnt2++;
            i++;
            }
        }
    }

    if(newlast){
        cout << cnt1 + cnt2*(K-1);
    } else if(plus){
        if(K % 2 == 1){
            cout << cnt1*(K / 2 + 1) + cnt2*(K / 2);
        } else{
            cout << cnt1*(K / 2) + cnt2*(K / 2);
        }
    } else{
        cout << cnt1*K ;
    }
}