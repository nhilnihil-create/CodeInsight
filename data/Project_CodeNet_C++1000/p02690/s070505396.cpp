#include <bits/stdc++.h>

using namespace std;

std::vector<pair<unsigned long long, unsigned long long>> prime_factors(unsigned long long number)
{
    std::vector<pair<unsigned long long,unsigned long long>> result;
    unsigned long long root = static_cast<unsigned long long>(std::sqrt(number));
    int count = 0;
    int leng = 0;
    int flag = 0;
    while (number % 2 == 0) {
        if(count == 0) {
            result.push_back(pair<unsigned long long, unsigned long long>(2,0));
            count += 1;
            flag = 1;
        }
        result[leng].second += 1;
        number = number / 2;
    }
    if (flag == 1) {
        leng++;
        flag = 0;
    }

    for (unsigned int i = 3; i <= root; i+=2) {
        count = 0;
        while (number % i == 0) {
            if(count == 0) {
                result.push_back(pair<unsigned long long, unsigned long long>(i,0));
                count += 1;
                flag = 1;
            }
            result[leng].second += 1;
            number = number /i;
        }
        if (flag == 1) {
            leng++;
            flag = 0;
        }
    }

    if(number > 2) {
        result.push_back(pair<unsigned long long, unsigned long long>(number,1));
    }

    return result;
}

long long func(long long a, long long b){
    return (a - b)*(pow(a,4) + pow(a,3) * pow(b,1) + pow(a,2) * pow(b,2) + pow(a,1) * pow(b,3) + pow(b,4));
}
int main(void)
{
    long long X;
    cin >> X;
    for(long long i = 0;i < 1000; i++) {
        for(long long j = -1000;j < 1000; j++) { 
            if(func(i,j) == X) {
                cout << i << " " << j << endl;
                return 0;
            }
        } 
    }
    return 0;

}