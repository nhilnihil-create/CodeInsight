#include <bits/stdc++.h>
using namespace std;

int main() {
    string S,CS,CS2,CS3;
    int N,ans=0;
    char num1,num2,num3;
    cin >> N;
    cin >> S;
    for(int i=0;i<10;i++){
        CS  = S;
        num1 = '0' + i;
        if(CS.find(num1)==string::npos){
                    continue;
                }
        else
        {
            CS.erase(0,CS.find(num1)+1);
        }
        
        for(int j=0;j<10;j++){
            CS2=CS;
            num2 = '0' + j;
            if(CS2.find(num2)==string::npos){
                    continue;
                }
            else
            {
                CS2.erase(0,CS2.find(num2)+1);
            }
            
            for(int k=0;k<10;k++){
                CS3=CS2;
                num3 = '0' + k;
                if(CS3.find(num3)==string::npos){
                    continue;
                }
                else
                {
                    ans++;
                }
            }
        }
    }

    cout << ans <<endl;

}