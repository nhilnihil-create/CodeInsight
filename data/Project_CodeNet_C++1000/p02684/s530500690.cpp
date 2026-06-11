#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++)
        cin >> A[i];

    int now = 1;
    long long rest = K;
    int result;
    int loop_start = -1;
    int dist = 1;
    bool flags[N+1];
    for(int i=0;i<=N;i++)
        flags[i] = false;

    while(1){
        int next = A[now];

        if(rest-- == 0){
            result = now;
            break;
        }

        else{
            if(loop_start < 0){ //ループを探索
                if(flags[next])
                    loop_start = next;
                else
                    flags[next] = true;  
            }

            else{ //１ループの長さを探索
                if(next == loop_start)
                    rest %= dist; //ループできるだけループする
                else
                    dist++;
            }
            now = next;
        }
    }

    cout << result;
    return 0;
}