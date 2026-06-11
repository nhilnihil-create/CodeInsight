#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
 
using namespace std;
 
int main(){
 
    int n,a,b,time,distance[10][10],min_value,min_index;
    int D[10],P[10],tmp_min,tmp_min_index,tmp_sum,count,max_number;
 
    while(true){
        scanf("%d",&n);
        if(n == 0)break;
 
        for(int i = 0; i < 10; i++){
            for(int k = 0; k < 10; k++)distance[i][k] = 2000000000;
        }
 
        max_number = -1;
        for(int i = 0; i < n; i++){
            scanf("%d %d %d",&a,&b,&time);
            distance[a][b] = time;
            distance[b][a] = time;
            max_number = max(max_number,max(a,b));
        }
 
        min_value = 2000000000;
 
        for(int town = 0; town <= max_number; town++){
            for(int i = 0; i <= max_number; i++){
                P[i] = 0;
                D[i] = 2000000000;
            }
 
            for(int i = 0; i <= max_number; i++){
                if(distance[town][i] >= 0){
                    D[i] = distance[town][i];
                }
            }
 
            count = 1;
            P[town] = 1;
            D[town] = 0;
 
            while(count <= max_number){
                tmp_min = 2000000000;
                for(int i = 0; i <= max_number; i++){
                    if(D[i] >= 0 && P[i] == 0 && D[i] < tmp_min){
                        tmp_min = D[i];
                        tmp_min_index = i;
                    }
                }
 
                if(tmp_min == 2000000000)break;
 
                P[tmp_min_index] = 1;
                count++;
 
                for(int k = 0; k <= max_number; k++){
                    if(D[k] > D[tmp_min_index] + distance[tmp_min_index][k]){
                        D[k] = D[tmp_min_index] + distance[tmp_min_index][k];
                    }
                }
            }
 
            tmp_sum = 0;
 
            for(int i = 0; i <= max_number; i++){
                tmp_sum += D[i];
            }
 
            if(tmp_sum < min_value){
                min_value = tmp_sum;
                min_index = town;
            }else if(tmp_sum == min_value && town < min_index){
                min_index = town;
            }
        }
 
        printf("%d %d\n",min_index,min_value);
 
    }
 
    return 0;
}
