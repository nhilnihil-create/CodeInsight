#include <iostream>
#include <vector>
using namespace std;
int N, M;
int As[100005];
int Bs[100005];
vector<int> bsHeap;
int job_selected[100005];

// struct greaters_As{  
//     bool operator()(const long& a,const long& b) const{  
//         return As[a]>As[b];  
//     }  
// };  

struct fewers_Bs{  
    bool operator()(const long& a,const long& b) const{  
        return Bs[a]<Bs[b] || (Bs[a] == Bs[b] && As[a]>As[b]);  
    }  
};  

int find(int idx){
    if (job_selected[idx]==0)
        return idx;
    
    return job_selected[idx] = find(job_selected[idx]);
}

int main(){
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= N; ++i){
        scanf("%d%d",&As[i],&Bs[i]);
        if(As[i]<=M)
            bsHeap.push_back(i);
    }

    make_heap(bsHeap.begin(), bsHeap.end(),fewers_Bs()); 
    int M1 = M;
    long long s = 0;
    for(int j = 0; j < M && bsHeap.size() > 0; ++j){
        int top = bsHeap.front();
        int count = 0;
        pop_heap(bsHeap.begin(), bsHeap.end(),fewers_Bs()); 
        bsHeap.pop_back(); 
        bool found = false;
        int i = As[top];
        while(i<=M){
            if(job_selected[i]==0){
                job_selected[i] = find(i+1);
                found = true;
                break;
            }
            i = find(i+1);
        }
        if(!found){
            j--;
        }else{
            s += Bs[top];
            // printf("%d\n",top);
        }
    }

    printf("%lld\n",s);

}