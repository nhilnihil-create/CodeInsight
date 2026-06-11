#include <iostream>
using namespace std;

int main(void){
    
    int N;
    string S;
    cin >> N >> S;
    
    int ans = 0;
    string pass;
    for(int i = 0; i < 1000; i++){
        
        // passwordの基準設定(000~999)
        pass = (i / 100) + '0'; 
        pass += ((i % 100) / 10) + '0';
        pass += (i % 10) + '0';
        
        int keta = 0;
        for(int j = 0; j < N; j++){
            if(pass[keta] == S[j]) keta++;
        }
        if(keta == 3) ans++;
    }
    
    cout << ans << endl;
}
