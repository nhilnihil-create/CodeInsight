#include <cstdio>
#define SIZE 244140625

char Key[128];

int Hash(const char* c)
{
    int Hash = 1;
    while(*c){
        Hash  <<= 2;
        Hash += Key[*c];
        ++c;
    }
    return Hash;
}
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
            dic[Hash(str+7)] = true;
        }else{
            std::puts((dic[Hash(str+5)] ? "yes" : "no"));
        }
    }
    return 0;
}