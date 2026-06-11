#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    unsigned N, M;
    scanf("%u %u", &N, &M);
    pair<unsigned, unsigned> p[N];
    for (size_t i = 0; i < N; i++){
        scanf("%u %u", &p[i].first, &p[i].second);
    }
    sort(p, p + N);
    unsigned it = 0, answer = 0;
    priority_queue<unsigned> pq;
    for (size_t days_until = 1; days_until <= M; days_until++){
        while(it < N && p[it].first == days_until){
            pq.push(p[it].second);
            it++;
        }
        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    printf("%u\n", answer);
	return 0;
}