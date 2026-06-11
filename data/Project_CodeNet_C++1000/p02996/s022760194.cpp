#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    unsigned N;
    scanf("%u", &N);
    pair<unsigned, unsigned> work[N];
    for (size_t i = 0; i < N; i++){
        scanf("%u %u", &work[i].second, &work[i].first);
    }
    sort(work, work + N, greater<pair<unsigned, unsigned> >());
    unsigned now = work[0].first;
    for (size_t i = 0; i < N; i++){
        if(min(now, work[i].first) < work[i].second){
            printf("No\n");
            return 0;
        }
        now = min(now, work[i].first) - work[i].second;
    }
    printf("Yes\n");
	return 0;
}