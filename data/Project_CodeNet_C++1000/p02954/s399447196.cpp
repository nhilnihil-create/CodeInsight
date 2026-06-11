#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    std::string S;   cin >> S;
    int L = S.length();
    int cnt = 0;
    S += 'R';
    std::vector<int> v(L,0);
    for(int i=0; i<L; i++){
        if(S[i] == 'R'){
            cnt++;
            if(S[i+1] == 'L'){
                if(cnt%2 == 1){
                    v[i] += cnt/2 + 1;
                    v[i+1] += cnt/2;
                }else{
                    v[i] += cnt/2;
                    v[i+1] += cnt/2;        
                }
                cnt = 0;
            }
        }else if(S[i] == 'L'){
            cnt++;
            if(S[i+1] == 'R'){
                if(cnt%2 == 1){
                    v[i - cnt] += cnt/2;
                    v[i - cnt + 1] += cnt/2 + 1;
                }else{
                    v[i - cnt] += cnt/2;
                    v[i - cnt + 1] += cnt/2;                   
                }
                cnt = 0;
            }
        }
    }
    for(int i=0; i<L; i++)
        cout << v[i] << " ";
}