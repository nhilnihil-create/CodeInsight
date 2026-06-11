#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S; 
    cin >> N;
    cin >> S;
    string P;
    int ans=0;
    for(int i=0; i<1000; i++){
        if(i<10) P="00"+to_string(i);
        else if(10<=i&&i<100) P='0'+to_string(i);
        else P=to_string(i);
        int now=0;
        for(int j=0; j<N; j++){
            if(P.at(now)==S.at(j)){
                if(now==0) now=1;
                else if(now==1) now=2;
                else{
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}