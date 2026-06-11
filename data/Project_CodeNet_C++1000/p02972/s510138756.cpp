#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

int main(){
    int N;
    cin >> N;
    vector<int> a(N+1);
    vector<int> box(N+1);
    stack<int> s;
    for(int i = 1; i <= N;i++) cin >> a[i];
    for(int i = N; i >= 1;--i){
        if(2 * i > N){
            box[i] = a[i];
            if(a[i] == 1) s.push(i);
        }
        else{
            int maxi = N / i;
            int mini = 2;
            int sum = 0;
            while(1){
                if(maxi < mini) break;
                if(maxi == mini){
                    sum += box[maxi * i];
                    break;
                }
                else sum += box[maxi * i] + box[mini * i];
                maxi--;mini++;
            }
            if((sum + a[i]) % 2 == 1){
                box[i] = 1;
                s.push(i);
            }
            else box[i] = 0;
        }    
    }
    if(s.empty()) cout << 0 << endl;
    else{
        cout << s.size() << endl;
        while(!s.empty()){
            cout << s.top() << endl;
            s.pop();
        }
    }
    return 0;
}