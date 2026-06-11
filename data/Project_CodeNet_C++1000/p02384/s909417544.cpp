#include <iostream>
#include <string>
using namespace std;

void North(int *nums){
    nums[6]=nums[0];
    nums[0]=nums[1];
    nums[1]=nums[5];
    nums[5]=nums[4];
    nums[4]=nums[6];
}
void East(int *nums){
    nums[6]=nums[0];
    nums[0]=nums[3];
    nums[3]=nums[5];
    nums[5]=nums[2];
    nums[2]=nums[6];
}
void South(int *nums){
    nums[6]=nums[0];
    nums[0]=nums[4];
    nums[4]=nums[5];
    nums[5]=nums[1];
    nums[1]=nums[6];
}
void West(int *nums){
    nums[6]=nums[0];
    nums[0]=nums[2];
    nums[2]=nums[5];
    nums[5]=nums[3];
    nums[3]=nums[6];
}
int main(void){
    int nums[7];
    int num;
    int a,b;
    
    for(int i=0;i<6;i++){
        cin>>nums[i];
    }
    nums[6]=0;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>a>>b;
        for(int i=0;i<4;i++){
            if(nums[0]==b)break;
            North(nums);
        }
        if(nums[0]!=b){
            West(nums);
            if(nums[0]!=b){
                East(nums);
                East(nums);
            }
        }
        South(nums);
        while(nums[0]!=a){
            West(nums);
        }
        cout<<nums[2]<<endl;
    }

    return 0;
}
