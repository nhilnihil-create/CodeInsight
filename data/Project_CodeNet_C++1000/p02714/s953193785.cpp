#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    long long ans = 0;
    char c;
    long long r = 0, g = 0, b = 0;

    std::cin >> N;
    vector<char> colors(N);

    for(int i = 0; i < N; i++){
        std::cin >> c;
        colors[i] = c;
        if(c == 'R'){
            r++;
        }else if(c == 'G'){
            g++;
        }else if(c == 'B'){
            b++;
        }
    }

    ans = r * g * b;

    for(int i = 0; i < N-2; i++){
        for(int j = i + 1; j < N-1; j++){
            // std::cout << i << " " << j << " " << 2*j -i << "\n";
            if(2*j -i < N){
                if(colors[i]+colors[j]+colors[2*j - i] == 219){
                    ans = ans - 1;
                }
            }
        }
    }

    std::cout << ans;
    // std::cout << 'R' + 'G' + 'B';

}