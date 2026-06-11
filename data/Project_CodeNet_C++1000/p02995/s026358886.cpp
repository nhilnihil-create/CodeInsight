#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
double min_double(double a,double  b){
    if(a<b) return a;
    else return b;
}
void swap(long long *x,long long *y){
    long long tmp;
    tmp=*x;
    *x=*y;  
    *y=tmp;
}

long long gcd(long long a,long long b){
    if(a<b) swap(&a,&b);
    if(b<1) return -1;

    if(a%b==0) return b;
    return gcd(b,a%b);
}

long long lcm(long long a,long long b){
    return a * b / gcd(a,b);
}
int main(){
    long long A,B,C,D;
    std::cin>>A>>B>>C>>D;

    if(C == 1 || D == 1){
        std::cout<<0<<std::endl;
        return 0;
    }

    long long num = B - A + 1;
    long long districtC1,districtC2;
    districtC1 = A / C;
    districtC2 = B / C;
    if(A % C == 0) districtC2++;
    long long districtC = districtC2 - districtC1;

    long long districtD1,districtD2;
    districtD1 = A / D;
    districtD2 = B / D;
    if(A % D == 0) districtD2++;
    long long districtD = districtD2 - districtD1;

    long long E = lcm(C,D);
    long long districtE1,districtE2;
    districtE1 = A / E;
    districtE2 = B / E;
    if(A % E == 0) districtE2++;
    long long districtE = districtE2 - districtE1;

    long long ans = num -districtC - districtD + districtE;

    std::cout<<ans<<std::endl;


    /*
    long long c = C,d = D;

    long long num = B - A + 1;

    long long E = C * D;
    long long e = E;

    long long districtC = 0;
    long long I = 1;
    while(1){
        c = C;
        c *= I;
        if(A <= c && c <= B) districtC++;
        else if(B < c) break;
        I++;
    }

    long long districtD = 0;
    I = 1;
    while(1){
        d = D;
        d *= I;
        if(A <= d && d <= B) districtD++;
        else if(B < d) break;
        I++;
    }

    long long districtE = 0;
    I = 1;
    while(1){
        e = E;
        e *= I;
        if(A <= e && e <= B) districtE++;
        else if(B < e) break;
        I++;
    }

    long long ans = num - districtC - districtD + districtE;

    std::cout<<ans<<std::endl;
    */
    

    return 0;
}

