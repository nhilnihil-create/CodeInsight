#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[128];
    char to[128];
    
    to['['] = ']';
    to['('] = ')';
    
    while (fgets(str, sizeof(str), stdin) != NULL){
        str[strlen(str) - 1] = 0;
        if (str[0] == '.' && str[1] == 0) break;
        
        char st[128];
        int ptr = 0;
        bool ok = true;
        
        for (int i = 0; str[i]; i++){
            if (str[i] == '(' || str[i] == '[') st[ptr++] = str[i];
            else if (str[i] == ')' || str[i] == ']'){
                if (ptr == 0 || to[st[--ptr]] != str[i]){
                    ok = false;
                    break;
                }
            }
        }
        
        printf("%s\n", ok && !ptr ? "yes" : "no");
    }
    
    return (0);
}