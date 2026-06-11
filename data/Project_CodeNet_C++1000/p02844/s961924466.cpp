#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<int> a(1000,0);
    int ans=0;
    for(int i=0;i<1000;i++){
        int t[3];
        int v=i;
        for(int k=0;k<3;k++){
            t[k]=v%10;
            v=v/10;
        }
        char t1=t[2]+'0',t2=t[1]+'0',t3=t[0]+'0';
        bool flag1=false, flag2=false;
        for(int k=0;k<S.size();k++){
            if(S[k]==t1) flag1 = true; 
            if(!flag1) continue;
            else{
                for(int l=k+1;l<S.size();l++){
                    if(S[l]==t2) flag2 = true;
                    if(!flag2) continue;
                    else{
                        for(int m=l+1;m<S.size();m++){
                            if(S[m]==t3) {
                                ans++;
                                break;
                            }
                        }
                    }
                    if(flag2) break;
                }
                if(flag1) break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}