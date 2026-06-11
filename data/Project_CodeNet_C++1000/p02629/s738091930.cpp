    #include <stdio.h>
     
    int main(){
        long long int w;
        scanf("%lld",&w);
     
        char name[100];
        int i=0;
        
        while(w!=0)
        {
            w--;
            int b = w%26;
            name[i] ='a'+ b;
            w/=26;
            i++;
        }
     
        for(int j=i-1;j>=0;j--)
        {
            printf("%c",name[j]);
        }
        
        return 0;
    }