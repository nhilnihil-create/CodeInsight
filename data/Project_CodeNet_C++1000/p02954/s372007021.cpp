#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;
    int children[100010]={0};
    int n=S.length();
    int i,j;

    for(i=0; i<n-1; i++){
        if(S[i]=='R'&& S[i+1]=='L'){
            children[i]++;
            children[i+1]++;
            j=i-1;
            while(j>=0){
                if(S[j]=='R') children[i+1]++;
                else break;
                j--;
                if(j>=0){
                    if(S[j]=='R') children[i]++;
                    else break;
                }
                j--;
            }
            j=i+2;
            while(j<=n-1){
                if(S[j]=='L') children[i]++;
                else break;
                j++;
                if(j<=n-1){
                    if(S[j]=='L') children[i+1]++;
                    else break;
                }
                j++;
            }
        }
    }

    for(i=0; i<n-1; i++){
        cout << children[i] << ' ';
    }
    cout << children[n-1] << endl;

    return 0;
}