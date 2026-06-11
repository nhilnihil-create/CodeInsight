#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const static int MOD = 1000000007;

int main(){
    unsigned N, K, C;
    scanf("%u %u %u\n", &N, &K, &C);
    bool can_work[N];
    vector<unsigned> candidate;
    for (unsigned i = 0; i < N; i++){
        char tmp;
        scanf("%c", &tmp);
        can_work[i] = tmp == 'o';
        if(can_work[i]) candidate.push_back(i);
    }
    scanf("\n");
    size_t _size = candidate.size(), j;
    unsigned after[_size+1], right_after[_size];
    after[_size] = 0;
    for (int i = _size - 1; i >= 0; i--){
        j = distance(candidate.begin(), upper_bound(candidate.begin(), candidate.end(), candidate[i] + C));
        right_after[i] = j;
        after[i] = 1 + after[j];
    }
    unsigned now = 0, n_selected = 0;
    unsigned selected[K];
    while(now != _size && n_selected < K){
        selected[n_selected] = now;
        now = right_after[now];
        n_selected++;
    }
    if(now != _size){
        printf("\n");
        return 0;
    }
    vector<unsigned> answer;
    for (size_t i = 0; i < K; i++){
        if(i + after[selected[i]+1] < K) answer.push_back(candidate[selected[i]] + 1);
    }
    for(auto p : answer) printf("%u\n", p);    
	return 0;
}