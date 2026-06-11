#include<cstdio>

class dice{
private:
	int a,b,c,d,e,f;
public:
	void setnumber(void);
	void E(void);
	void W(void);
	void S(void);
	void N(void);
	void printa(void);
};

void dice::setnumber(void){
scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
}

void dice::E(void){
int a1=a,c1=c,d1=d,f1=f;
a=d1;
c=a1;
d=f1;
f=c1;
}

void dice::W(void){
int a1=a,c1=c,d1=d,f1=f;
a=c1;
c=f1;
d=a1;
f=d1;
}

void dice::S(void){
int a1=a,b1=b,e1=e,f1=f;
a=e1;
b=a1;
e=f1;
f=b1;
}

void dice::N(void){
int a1=a,b1=b,e1=e,f1=f;
a=b1;
b=f1;
e=a1;
f=e1;
}

void dice::printa(void){
printf("%d\n",a);
}

int main(void){
dice koro;
char ch[101];
int i=0;
koro.setnumber();
scanf("%s",ch);
while(ch[i]!='\0'){

	if(ch[i]=='E'){
		koro.E();
	}else if(ch[i]=='W'){
		koro.W();
	}else if(ch[i]=='S'){
		koro.S();
	}else if(ch[i]=='N'){
		koro.N();
	}
	i++;
}

koro.printa();

return 0;
}

		