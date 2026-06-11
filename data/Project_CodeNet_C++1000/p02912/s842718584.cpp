#include <iostream>
#include <math.h> 
#include <vector>
using namespace std;
int N, M;
vector<double> As;
// long long opt[2][100005];
int main(){
    scanf("%d%d", &N, &M);
    for (int i = 1; i<= N; ++i){
        int A;
        scanf("%d",&A);
        As.push_back(double(A));
    }

    make_heap(As.begin(), As.end()); 

    while(M>0){
        double top = As.front() ;
        pop_heap(As.begin(), As.end()); 
        As.pop_back(); 

        As.push_back(top/2); 
      
        // using push_heap() to reorder elements 
        push_heap(As.begin(), As.end());
        M--;
    }

    long long result = 0;
    for(int i = 0; i < As.size();++i)
        result += int(As[i]);

    // for(int i = 0; i <= M; ++i){
    //     opt[0][i] = 0;
    // }

    // for (int i = 1; i<= N; ++i){
    //     for(int j = 0; j <= M; ++j){
    //         opt[i%2][j] = opt[(i-1)%2][0] + As[i];
    //         for(int k = 0; k <= M; ++k){
    //             long long tmp = opt[(i-1)%2][k] + int(As[i]/pow(2,j-k));
    //             if (tmp >= opt[i%2][j])
    //                 break;
    //             opt[i%2][j] = tmp;
    //         }
    //     }
    // }

    printf("%lld\n",result);

}