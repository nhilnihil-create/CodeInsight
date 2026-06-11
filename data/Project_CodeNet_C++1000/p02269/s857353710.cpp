#include <cstdio>
#define SIZE 33554432
char Key[128];
int Hash;
char* c;
#define HASH(A) c = A; Hash = 1; while(*c){ Hash <<= 2; Hash += Key[*c]; ++c;}
int main()
{
    Key['A'] = 0;
    Key['C'] = 1;
    Key['G'] = 2;
    Key['T'] = 3;
    bool* dic = new bool[SIZE];
    int n;
    std::scanf("%d\n", &n);
    char str[21];
    for(int i = 0; i < n; ++i){
        std::gets(str);
        if(str[0] == 'i'){
            HASH(str+7)
            dic[Hash] = true;
        }else{
            HASH(str+5)
            std::puts((dic[Hash] ? "yes" : "no"));
        }
    }
    return 0;
}