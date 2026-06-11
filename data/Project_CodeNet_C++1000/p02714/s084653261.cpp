#include<cstdio>
using ull = unsigned long long;

int main(){
    unsigned N;
    scanf("%u\n", &N);
    char S[N+1];
    scanf("%s", S);
    ull r = 0, g = 0, b = 0;
    for (size_t i = 0; i < N; i++){
        if(S[i] == 'R') r++;
        else if(S[i] == 'G') g++;
        else b++;
    }
    ull answer = r*g*b;
    for (size_t i = 1; i <= N - 1 >> 1; i++){
        for (size_t j = 0; j + i*2 < N; j++){
            if(S[j] != S[j + i] && S[j + i] != S[j + i*2] && S[j + i*2] != S[j]) answer--;
        }
    }
    printf("%llu\n", answer);    
	return 0;
}