#include <stdio.h>
#include <string.h>
char s[10010];
int a[26], i, l;
main()
{
    while(scanf("%s", s)!=EOF)
    {
        l=strlen(s);
        for(i=0; i<l; i++)
        {
            if(s[i]==' ') continue;
            if(s[i]>='A' && s[i]<='Z') a[s[i]-'A']++;
            else if(s[i]>='a' && s[i]<='z') a[s[i]-'a']++;
        }

    }

    for(i=0; i<26; i++)
    {
        printf("%c : %d\n", 'a'+i, a[i]);
    }

}

