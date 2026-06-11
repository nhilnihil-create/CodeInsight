#include <iostream>
#include <vector>

std::vector<int> UFT;
int Find(int a);
void Unite(int a,int b);
int main() {
    int N,M;
    std::cin >> N >> M;
    UFT.resize(N+1,0);
    for(int i=0;i<M;i++){
        int a,b;
        std::cin >> a >> b;
        int small,large;
        if(a>b){
            small = b;
            large = a;
        }else{
            small = a;
            large = b;
        }
        Unite(small,large);
    }
    for(int i=1;i<=N;i++){
        Find(i);
    }
    std::vector<int> cnt(N+1,0);
    for(int i=1;i<=N;i++){
        if(UFT[i] == 0){
            cnt[i]++;
        }else {
            cnt[UFT[i]]++;
        }
    }
    int max = 0;
    for(int i=1;i<=N;i++){
        if(cnt[i] > max){
            max = cnt[i];
        }
    }
    std::cout << max;

    return 0;
}

void Unite(int a,int b){
    int rootA,rootB;
    rootA = Find(a);
    rootB = Find(b);
    if(rootA == rootB){
        return;
    }
    UFT[rootB] = rootA;
    return;
}

int Find(int a){
    if(UFT[a] != 0){
        int root = Find(UFT[a]);
        UFT[a] = root;
        return root;
    }
    return a;
}