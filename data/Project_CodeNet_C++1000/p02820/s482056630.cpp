#include<cstdio>

int main(){
    unsigned N, K, R, S, P;
    scanf("%u %u\n%u %u %u\n", &N, &K, &R, &S, &P);
    char T[N+1];
    scanf("%s", T);
    bool win[N];
    unsigned answer = 0;
    for (size_t i = 0; i < K; i++){
        win[i] = true;
        if(T[i] == 'r') answer += P;
        else if(T[i] == 's') answer += R;
        else answer += S;
    }
    for (size_t i = K; i < N; i++){
        win[i] = (T[i] != T[i - K]) || !win[i - K];
        if(win[i]){
            if(T[i] == 'r') answer += P;
            else if(T[i] == 's') answer += R;
            else answer += S;
        }
    }
    printf("%u\n", answer);
	return 0;
}