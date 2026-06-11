#include<iostream>
char judge(int m,int r,int f){
    char grade;
    int sum=m+r;
    if(m==-1 || r==-1) grade='F';
    else if(sum>=80) grade='A';
    else if(sum>=65) grade='B';
    else if(sum>=50) grade='C';
    else if(sum>=30){
        grade='D';
        if(f>=50) grade='C';
    }
    else grade='F';
    return grade;
}
int main(void){
    int m,r,f;
    while(1){
        std::cin>>m>>r>>f;
        if(m==-1&&r==-1&&f==-1) break;
        std::cout<<judge(m,r,f)<<std::endl;
    }
    return 0;
}