#include<iostream>
#include<string>
#include<queue>
using namespace std;

string s;
int x[100000],y[100000],ans[100000];

int main(){  
    cin >> s;
    for(int i = 0;i < s.size() - 1;i++){
        if(x[i] == -1) continue;
        if(s.at(i) == 'R' && s.at(i + 1) == 'L'){
            x[i] = -1;
            x[i + 1] = -1;
        }
        else if(s.at(i) == 'R'){
            x[i] = 2;
        }
        else{
            x[i] = 1;
        }
    }

    int n = s.size();

    if(x[n - 1] != -1){
        x[n - 1] = 1;
    }

    int roop = 0;

    for(int i= 0;i < s.size();i++){
        switch(x[i]){
            case -1:
            y[i] = -1;
            roop = i;
            ans[i]++;
            break;
            case 1:
            y[i] = i - roop;
            if(y[i]%2 == 0){
                ans[roop]++;
            }
            else{
                ans[roop - 1]++;
            }
            break;
            case 2:
            break;
        }
    }

    for(int i= s.size() - 1;i >= 0;i--){
        switch(x[i]){
            case -1:
            y[i] = -1;
            roop = i;
            ans[i]++;
            break;
            case 1:
            break;
            case 2:
            y[i] = roop - i;
            if(y[i]%2 == 0){
                ans[roop]++;
            }
            else{
                ans[roop + 1]++;
            }
            break;
        }
    }



    for(int i = 0;i < s.size();i++){
        if(ans[i] > 0){
            ans[i]--;
        }
        cout << ans[i] << " " ;
    }

   cout << endl;
}