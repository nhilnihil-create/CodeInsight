#include <stdio.h>
#include <cstring>

using namespace std;

int get_index(int value, int dice[]){
    for(int i = 0; i < 6; i++){
        if(dice[i] == value){
            return i + 1;
        }
    }
}

bool match_pattern(int upper_key, int front_key, int pattern[]){
    for(int i = 0; i < 5; i++){
        if(pattern[i] == upper_key){
            if(pattern[i+1] == front_key){ 
                return true;
            }
        }
    }
    return false;
}

int main(){
    int dice[6];
    int q;
    for(int i = 0; i < 6; i++) scanf("%d",&dice[i]);
	scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int upper, front;
        scanf("%d", &upper);
        scanf("%d", &front);
        int upper_key = get_index(upper, dice);
        int front_key = get_index(front, dice);
        
        int pattern3 [5] = {1,2,6,5,1};
        int pattern4 [5] = {5,6,2,1,5};
        int pattern1 [5] = {4,2,3,5,4};
        int pattern6 [5] = {5,3,2,4,5};
        int pattern5 [5] = {1,3,6,4,1};
        int pattern2 [5] = {4,6,3,1,4};

        if(match_pattern(upper_key, front_key, pattern3)){
            printf("%d\n", dice[2]);
            continue;
        }else if(match_pattern(upper_key, front_key, pattern4)){
           printf("%d\n", dice[3]);
            continue;
        }else if(match_pattern(upper_key, front_key, pattern1)){
            printf("%d\n", dice[0]);
            continue;
        }else if(match_pattern(upper_key, front_key, pattern6)){
            printf("%d\n", dice[5]);
            continue;
        }else if(match_pattern(upper_key, front_key, pattern5)){
            printf("%d\n", dice[4]);
            continue;
        }else if(match_pattern(upper_key, front_key, pattern2)){
            printf("%d\n", dice[1]);
            continue;
        }
    
    }
}

/*
1 2 3 4 5 6
3
6 5
1 3
3 2

answer
3
5
6
*/
