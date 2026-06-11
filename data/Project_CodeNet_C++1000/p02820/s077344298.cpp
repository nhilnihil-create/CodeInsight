#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    int score = 0;

    queue<int> cmdBuf;
    string buffer = "";
    for (int i = 0; i < N; i++)
    {

        int command = 0;
        if (T[i] == 'r')
        {
            if(i < K){
                buffer.push_back('p');
                command = P;
            } else {
                if(buffer[i-K] != 'p'){
                    buffer.push_back('p');
                    command = P;
                } else {
                    buffer.push_back('x');
                }
            }
            
        }
        else if (T[i] == 's')
        {
            if(i < K){
                buffer.push_back('r');
                command = R;
            } else {
                if(buffer[i-K] != 'r'){
                    buffer.push_back('r');
                    command = R;
                } else {
                    buffer.push_back('x');
                }
            }
        }
        else
        {
            if(i < K){
                buffer.push_back('s');
                command = S;
            } else {
                if(buffer[i-K] != 's'){
                    buffer.push_back('s');
                    command = S;
                } else {
                    buffer.push_back('x');
                }
            }
        }
        score += command;
    }

    cout << score << endl;

    return 0;
}
