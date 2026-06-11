#include <iostream>
#include <string>
std::string S;
long table[100000+1][13];
long MOD=1000000000+7;
void solve()
{
    for(long i=1;i<S.length();i++){
        char num_S=S[i];
        for(long j=0; j<13; j++){
            if(num_S!='?'){
                long num=num_S-'0';
                table[i][(num+10*j)%13]+=table[i-1][j];
                table[i][(num+10*j)%13]%=MOD;
            }else{
                for(long k=0; k<=9; k++){
                    table[i][(k+10*j)%13]+=table[i-1][j];
                    table[i][(k+10*j)%13]%=MOD;
                }
            }
        }
    }
}

void init()
{
    for(long i=0; i<100000+1;i++){
        for(long j=0; j<13; j++){
            table[i][j]=0;
        }
    }
    if(S[0]=='?'){
        for(long i=0; i<=9; i++){
            table[0][i]=1;
        }
    }else{
        table[0][S[0]-'0']=1;
    }
}

int main(void){
    std::cin >> S;
    init();
    solve();
    std::cout << table[S.length()-1][5] << std::endl;
    return 0;
}