#include<bits/stdc++.h>

double th = M_PI * 60.0 / 180.0;

int cnt, n;


int koch(int n, std::vector<double> left, std::vector<double> right){
    
    if(n == 0){
        return 0;
    } 
  
    std::vector<double> m1(2);
    std::vector<double> m2(2);
    std::vector<double> m3(2);

    m1[0] = left[0] + (right[0] - left[0]) / 3.0;
    m1[1] = left[1] + (right[1] - left[1]) / 3.0;

    koch(n-1, left, m1);


    printf("%lf %lf\n", m1[0], m1[1]);


    m2[0] = left[0] + (right[0] - left[0]) * 2.0 / 3.0;
    m2[1] = left[1] + (right[1] - left[1]) * 2.0 / 3.0;

    double xm3 = m2[0] - m1[0];
    double ym3 = m2[1] - m1[1];

    m3[0] = cos(th) * xm3 - sin(th) * ym3 + m1[0];
    m3[1] = sin(th) * xm3 + cos(th) * ym3 + m1[1]; 
 
    koch(n-1, m1, m3);

    printf("%lf %lf\n", m3[0], m3[1]);

    koch(n-1, m3, m2);

    printf("%lf %lf\n", m2[0], m2[1]);

    koch(n-1, m2, right);


    
    
}

int main(void){
    std::vector<double> left = {0, 0};
    std::vector<double> right = {100, 0};
    cnt = 0;

    scanf("%d", &n);

    printf("%lf %lf\n", left[0], left[1]);

    koch(n, left, right);

    printf("%lf %lf\n", right[0], right[1]);


    return 0;
}
