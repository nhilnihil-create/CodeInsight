#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    long long int i, x, N , K, score, score_max, cycle, K_rem, ans;
    cin >> N >> K;
    score = 0;
    score_max = 0;
    cycle = 0;
    
    long long int P[N], C[N], Sc[N], Sm[N], Cy[N], Max[N];
    
    for (i = 0; i < N; i++){
        cin >> P[i];
        P[i] -= 1;
    }

    for (i = 0; i < N; i++){
        cin >>C[i];
    }
    
    x = C[0];

    for (i = 0; i < N; i++){
        x = max(x, C[i]);
    }
    
    if (x <= 0){
        cout << x << "\n";
        return 0;
    }

    for (i = 0; i < N; i++){
        x = i;
        score = 0;
        cycle = 0;
        score_max = 0;

        while (1){
            x = P[x];
            score += C[x];
            score_max = max(score, score_max);
            cycle++;
            if (x == i) break;
        }

        Cy[i] = cycle;
        Sc[i] = score;
        Sm[i] = score_max;
    }
    
    for (i = 0; i < N; i++){
        x = i;
        score = 0;
        cycle = 0;
        score_max = 0;
        K_rem = (K - 1) % Cy[i] + 1;

        while (1){
            x = P[x];
            score += C[x];
            score_max = max(score, score_max);
            cycle++;
            if (cycle == K_rem) break;
        }
        
        if (Sc[i] <= 0){
            Max[i] = Sm[i];
        } else {
            Max[i] = (K - 1) / Cy[i] * Sc[i] + score_max;
        }

    }
    
    ans = 0;
    
    for (i = 0; i < N; i++){
        ans = max(ans, Max[i]);
    }
    
    cout << ans << "\n";
    
    return 0;
}
